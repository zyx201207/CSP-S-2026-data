#include<bits/stdc++.h>
using namespace std;
struct Node{
	long long num;
	char ch;
};
Node a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].ch;
	}
	long long t1=0,t2=0,cnt=0,u1=1,u2=n;
	while(u1<=n){
		// cout<<u1<<" "<<u2<<" "<<t1<<" "<<t2<<" "<<cnt<<endl;
		if(a[u1].ch!=a[u2].ch){
			cnt+=min(a[u1].num+t1-max(t1,t2),a[u2].num+t2-max(t1,t2));
		}
		if(a[u1].num+t1>a[u2].num+t2){
			t2+=a[u2].num;
			u2--;
		}
		else if(a[u1].num+t1<a[u2].num+t2){
			t1+=a[u1].num;
			u1++;
		}
		else if(a[u1].num+t1==a[u2].num+t2){
			t2+=a[u2].num;
			u2--;
			t1+=a[u1].num;
			u1++;
		}
	}
	cout<<cnt/2;
	
	return 0;
}
