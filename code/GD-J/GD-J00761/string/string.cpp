#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int n,a[N],ans,x,T,len;
char c[N],ch;
signed main(){
	freopen("string5.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>ch;
		len+=x;
		if(ch==c[T]){
			a[T]+=x;
		}
		else a[++T]=x,c[T]=ch;
	}
	n=T;
	if(len<1e8){
		string s;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i];j++){
				s+=c[i];
			}
		}
		for(int i=0,j=s.size()-1;i<=j;i++,j--){
			if(s[i]!=s[j]) ans++;
		}
		cout<<ans;
		return 0;
	}
	int i=1,j=n;
	while(i<=j){
		if(a[i]==a[j]) ans+=(c[i]!=c[j])*a[i],j--,i++;
		else{
			int t;
			if(c[i]==c[j]){
				t=abs(a[i]-a[j]);
				ans+=t;
				if(a[i]>a[j]) j--;
				else i++;
			}
			else{
				t=max(a[i],a[j]);
				ans+=t;	
			}
			if(a[i]>a[j]){
				while(j>i){
					if(a[j]>=t){
						a[j]-=t;
						t=0;
						break;
					}
					else t-=a[j],a[j]=0;
					j--;
				}
				i++;
			}
			else{  
				while(j>i){
					if(a[i]>=t){
						a[i]-=t;
						t=0;
						break;
					}
					else t-=a[i],a[i]=0;
					i++;
				}
				j--;
			}	
		}
	}
	cout<<ans;
	return 0;
} 
