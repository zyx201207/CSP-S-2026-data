#include <bits/stdc++.h>
using namespace std;
const int MA=114514;
int n,m,a[5*MA],ans[3*MA];
bool tmp[3*MA];
bool A=1;
stack <int> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)cin >> a[i];
	for(int i=1;i<=n-1;i++)
		if(a[i]>a[i+1])A=0;
	if(A){
		for(int i=1;i<=m;i++)cout << i << ' ';
		return 0;
	}
	for(int i=1;i<=n;i++){
		memset(tmp,0,sizeof(tmp));
		for(int j=i;j<=n;j++){
			if(!tmp[a[j]]){
				s.push(a[j]);
				tmp[a[j]]=1;
			}else while(s.top()!=a[j]&&!s.empty()){
				tmp[s.top()]=0;
				s.pop();
			}			
		}
		while(!s.empty()){
			ans[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++)cout << ans[i] << ' ';
	return 0;
}
