#include<bits/stdc++.h>
using namespace std;
#define N 500005
#define M 300005
int n,m,a[N],ans[M],under[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		stack<int> s;
		bool b[M];
		for(int i=1;i<=m;i++)b[i]=0;
		for(int i=1;i<=m;i++)under[i]=0;
		for(int j=i;j<=n;j++){
			if(!b[a[j]]){
				s.push(a[j]),b[a[j]]=1;
				under[a[j]]=s.size();
				ans[a[j]]++;
				//for(int i=1;i<=m;i++)cout<<under[i]<<' ';
				//cout<<endl;
			}
			else{
				//cout<<s.size()<<' '<<under[a[j]]<<' ';
				while(s.size()>under[a[j]]){
					int t=s.top();//¥Ê∑≈’ª∂•
					//cout<<t<<' '<<s.size()<<' '; 
					s.pop();
					ans[t]--;
					b[t]=0;
					//cout<<ans[t]<<' '<<b[t]<<endl;
				}
				//cout<<"«Âø’"<<' ';for(int i=1;i<=m;i++)cout<<ans[i]<<' ';cout<<endl;
			}
			//cout<<i<<endl;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
}
