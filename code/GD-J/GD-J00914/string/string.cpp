#include<bits/stdc++.h>
using namespace std;
long long n,ans,minn=10000000000000;
const int N=2e5+10;
long long a[N];
string b[N];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		for(long long j=1;j<=a[i];j++){
			s+=b[i];
		}
	}
	int len=s.size()/2+1;
	string s1=s;
	reverse(s1.begin(),s1.end());
	if(s==s1){
		cout<<"0";
		return 0;
	}else{
		for(int i=0;i<s.size();i++){
			s1=s;
		    reverse(s1.begin(),s1.end());
		    if(s1==s){
		    	minn=min(minn,ans);
			}else{
				string m,w,m1,w1;
				int vis[N],k=0,maxn=-1,num[N];
				for(int j=0;j<len;j++){
					m+=s[j];
					vis[s[j]]==1;
					num[s[j]]++;
				}
				for(int j=len+1;j<s.size();j++){
					w+=s[j];
					num[s[j]]++;
					if(vis[s[j]]==1&&maxn<num[s[j]]){
						k=j;
						maxn=num[s[j]];
					}
				}
				m1=m,w1=w;
				reverse(m1.begin(),m1.end());
				reverse(w1.begin(),w1.end());
				if(m!=m1){
					for(int j=0;j<m.size();j++){
						if(s[j]!=s[k]){
							s[j]=s[k];
							ans++;
					    }
					}
				}else if(w!=w1){
					for(int j=0;j<w.size();j++){
						if(s[j]!=s[k]){
							s[j]=s[k];
							ans++;
						}
					}
				}else if(w==w1&&m==m1){
					cout<<min(minn,ans);
					return 0;;
				}
			}	
		}
	}
	return 0;
} 
