#include<bits/stdc++.h>
using namespace std;
int n;
int m;
const int N=5e5+5;
vector<int>a;
int q[N];
int ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	a.push_back(0);
	for(int i=1;i<=n;i++){
		int x; scanf("%d",&x);
		a.push_back(x);
	}
	ans[a[n]]=n;
	int head=1,tail=0;
	for(int i=1;i<=m;i++){
		for(int a=1;a<=n;a++){
		for(int j=a;j<=n;j++){
			for(int k=head;k<=tail;k++){
				if(q[k]==i)while(tail<k)tail--;
			}
		}
		ans[i]++;
	}
		
	}
	ans[a[n]]=n;
	for(int i=1;i<=m;i++)printf("%d ",ans[i]);
	return 0;
}
