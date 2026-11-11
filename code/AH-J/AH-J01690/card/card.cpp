#include<bits/stdc++.h> 
using namespace std;
stack<int> s;
int n,m,t[100005],a[1000005],f[3005],fl,b[100005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
		if(a[i]<=a[i-1])
			fl=1;
	}
	if(fl==0){
		for(int i=1;i<=m;i++)
			if(b[i]%2==1)
				cout<<i+b[i]/2<<' ';
			else
				cout<<b[i]/2<<' ';
		return 0;
	}
	for(int i=1;i<=n;i++){
		//memset(f,0,sizeof(f));
		for(int j=i;j<=n;j++){
			if(f[a[j]]==0){
				s.push(a[j]);
				f[a[j]]=1;
			}
			else{
				while(s.top()!=a[j]){
					f[s.top()]=0;
					s.pop();
				}
			}
		}
		while(!s.empty()){
			t[s.top()]++;
			f[s.top()]=0;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++)
		cout<<t[i]<<' ';
	return 0;
}
