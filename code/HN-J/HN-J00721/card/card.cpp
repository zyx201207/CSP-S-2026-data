#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],ans[300005],t[500005],f=0;
bool st[300005];
int p(int num){
	//cout<<num;
	if(num<=n){
		if(st[a[num]]==1){
			while(t[f]!=a[num]){
				st[t[f]]=0;
				f--;
			}
		}
		else{
			st[a[num]]=1;
			f++;
			t[f]=a[num];
		}
		/*for(int i=1;i<=f;i++){
			cout<<t[i]<<" ";
		}cout<<num<<"-end\n";*/
		p(num+1);
	}
	else{
		//cout<<"round over\n";
		return 0;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
	//	cout<<1;
		p(i);
		while(f>0){
			ans[t[f]]++;
			st[t[f]]=0;
			//cout<<t[f]<<" clean  ";
			f--;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
}
