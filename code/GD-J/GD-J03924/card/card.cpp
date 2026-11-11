#include<bits/stdc++.h>
using namespace std;
int m,n,a[500005],l[300005];
bool c[300005],p;
stack<int> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int r=1;r<=n;r++)
		for(int i=r;i<=n;i++){
			if(!c[a[i]]){
				s.push(a[i]);
				c[a[i]]=1;
			}
			else{
				while(s.top()!=a[i]){
					p=0;
					for(int j=i+1;j<=n;j++){
						if(a[j]==s.top()){
							p=1;
							break;
						}
					}
					if(!p)l[s.top()]=i;
					c[s.top()]=0;
					s.pop();
				}
			}
		}
	for(int i=1;i<=m;i++)cout<<l[i]<<' ';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
