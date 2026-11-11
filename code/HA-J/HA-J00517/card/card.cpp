#include<bits/stdc++.h>
using namespace std;
string s;
struct str{
	bool f=0;
	int x;
};
long long n,a[50005],m,b[30005];
long long sum;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		str t[30005];
		for(int j=i;j<=n;j++){
			if(t[a[j]].f==1){
				for(int k=t[a[j]].x+1;k<=j;k++){
					t[k].f=0;
					t[k].x=0;
				}
			}
			t[a[j]].f=1;
			t[a[j]].x=j;
		}
		for(int j=1;j<=m;j++){
			if(t[j].f==1){
				b[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
	return 0;
}
