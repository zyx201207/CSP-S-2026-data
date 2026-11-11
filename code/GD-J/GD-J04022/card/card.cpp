#include <bits/stdc++.h>
using namespace std;
int a[500005];
int ans[300005];
struct edge{
	int k;
	int lst,nxt;
}q[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i];
	if(n<=500){
		int front;
		for(int i=1;i<=n;i++){
			front=i;
			q[i].k=a[i];
			q[i].nxt=i+1;
			for(int j=i+1;j<=n;j++){
				q[j].k=a[j];
				q[j].lst=j-1;
				q[j].nxt=0;
				q[j-1].nxt=j;
				for(int tmp=front;tmp;){
					if(q[tmp].k==q[j].k){
						if(front==tmp)	front=j;
						int temp=q[tmp].lst;
						q[temp].nxt=j;
						q[j].lst=temp;
						break;
					}
					tmp=q[tmp].nxt;
				}
			}
			for(int tmp=front;tmp;){
				int temp=q[tmp].k;
				ans[temp]++;
				tmp=q[tmp].nxt;
			}
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
		return 0;
	}
	else if(m==1){
		cout<<n;
		return 0;
	}
	else if(m==2){
		int tmp=a[n];
		int sum=0;
		for(int i=1;i<=n;i++){
			if(a[i]==tmp)	sum++;
		}
		if(tmp==1){
			cout<<n<<' '<<n-sum;
		}
		else	cout<<n-sum<<' '<<n;
		return 0;
	}
	for(int i=1;i<=n;i++){
		while(a[i]==a[i+1]){
			i++;
		}
		cout<<i<<' ';
	}
	return 0;
}
