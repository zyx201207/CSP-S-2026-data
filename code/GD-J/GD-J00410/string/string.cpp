#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=200005;
string s;
char flag;
int n,ans,flag2;
int a[MAXN];
char c[MAXN];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n; 
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(!flag2){
			flag=c[i];
			flag2=1;
			continue;
		}
		if(c[i]!=flag){
			flag='0';
		}
	}
	if(flag!='0'){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n/2;i++){
		if(a[i]==a[n-i+1]&&c[i]==c[n-i+1]) continue;
		if(c[i]==c[n-i+1]){
			//cout<<c[i]<<"==!"<<c[n-i+1]<<endl;
			int tmp=max(a[i]-a[n-i+1],a[n-i+1]-a[i]);
			ans+=tmp;
			tmp-=a[i];
			while(tmp>0){
				int j=i;
				if(a[j+1]<tmp){
					a[j+1]=0;
					n-=1;
					i++;
					tmp-=a[j+1];
				}else{
					a[j+1]-=tmp;
					tmp=0;
				}
				j++;
			}
		}else{
			int tmp=max(a[i],a[n-i+1]);
			ans+=tmp;
			tmp-=a[i]; 
			while(tmp>0){
				int j=i;
				if(a[j+1]<tmp){
					a[j+1]=0;
					n-=1;
					i++;
					tmp-=a[j+1];
				}else{
					a[j+1]-=tmp;
					tmp=0;
				}
				j++;
			}
		}
		
	}
	cout<<ans;
	return 0;
}
/*
5
2 r
2 k
2 y
3 k
4 z
*/
