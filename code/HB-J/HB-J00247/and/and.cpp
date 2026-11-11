#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
string s[200005],l;
int maxn,ans;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n,cmp);
	
	for(int i=1;i<=n;i++){
		int k=a[i];
		while(k!=0){
			if(k%2==1) s[i]='1'+s[i];
			else s[i]='0'+s[i];
			k/=2;
			}
			
	}
	maxn=int(s[m].size());
	for(int i=maxn-1;i>=0;i--){
		bool flag=1;
	    for(int j=1;j<=m;j++)
	    {
			if(s[j][int(s[j].size())-i-1]=='0')
			{
			
			flag=0;
			break;	
				}
		}
		if(flag) ans+=pow(2,i);
		
		}
		cout<<ans;
	return 0;
	}



