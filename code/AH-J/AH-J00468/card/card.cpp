#include<bits/stdc++.h>
using namespace std;
vector <int> s;
const int N=500001;
typedef long long LL;
LL n,m,a[N],b[N]={0};
void doing(int x){
	for(int i=x; i<=n; i++){
		if(s.empty() || find(s.begin(),s.end(),a[i])==s.end())s.push_back(a[i]);
		else if(!s.empty() &&!(find(s.begin(),s.end(),a[i])==s.end()))
		while(s.front()!=a[i])s.resize(s.size()-1);
}
while(!s.empty()){
	LL k=s.front();
	b[k]++;
	s.resize(s.size()-1);
}
}
int main(){ 
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
cin>>n>>m;
for(int i=1; i<=n; i++)cin>>a[i];
for(int i=1; i<=n; i++)doing(i);
for(int i=1; i<=m; i++)cout<<b[i]<<" ";
return 0;
}
