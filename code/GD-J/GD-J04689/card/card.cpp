#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i=0;i<n;i++){
		stack<int> s;
		bool cnt[N]={};
		for(int j=i;j<n;j++){
			if(cnt[a[j]]){
				while(s.top()!=a[j]){
					cnt[s.top()]=false;
					ans[s.top()]--;
					s.pop();
				}
			}else{
				s.push(a[j]);
				cnt[a[j]]=true;
				ans[a[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout << ans[i] << ' ';
	}
	fclose(stdin);
	fclose(stdout);
}
