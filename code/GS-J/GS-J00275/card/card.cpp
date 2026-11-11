#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],cnt[500010];
struct dc{
	int wei;
	bool f;
};
dc ch[500010];
string s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(ch[a[j]].f==1)
			{
				for(int k=ch[a[j]].wei;k<=j;k++){
					s[k]='0';
					ch[a[k]].f=0;
					
				}
			}
			s+=a[j];
			ch[a[j]].f=1;
			ch[a[j]].wei=j-i+1;		
		}
		for(int j=1;j<=n;j++){
			cnt[s[j]]++;
		}
		s="";
	}
	for(int i=1;i<=m;i++)	cout<<cnt[i]<<" ";
	return 0;
}
