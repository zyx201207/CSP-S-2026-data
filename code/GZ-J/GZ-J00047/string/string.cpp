//GZ-J00047 贵阳市第一中学 刘一萱 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
ll n,a1[N],sum,n1;
ll w1,w2,w3,w4,w5,w6,w7;
char a[N],a2[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if (n&1){
		n1=n/2+1;
	}
	else{
		n1=n/2;
	}
	for (int i=1;i<=n;i++){
		cin>>a1[i]>>a2[i];
		w4+=a1[i];
	}
	if (w4&1){
		w7=w4/2+1;
	}
	else{
		w7=w4/2;
	}
	w5=1,w6=1;
	w1=1,w2=n,w3=1;
	while(w1<=n && w2>=1){
		if (a1[w1]-w5>a1[w2]-w6){
			if (a2[w1]!=a2[w2]){
				sum+=a1[w2]-w6+1;
			}
			w4-=a1[w2]-w6+1;
			w3+=a1[w2]-w6+1;
			w5+=a1[w2]-w6+1;
			w2-=1;
			w6=1;
		}
		else if (a1[w1]-w5<a1[w2]-w6){
			if (a2[w1]!=a2[w2]){
				sum+=a1[w1]-w5+1;
			}
			w3+=a1[w1]-w5+1;
			w4-=a1[w1]-w5+1;
			w6+=a1[w1]-w5+1;
			w1+=1;
			w5=1;
		}
		else if (a1[w1]-w5==a1[w2]-w6){
			if (a2[w1]!=a2[w2]){
				sum+=a1[w1]-w5+1;
			}
			w3+=a1[w1]-w5+1;
			w4-=a1[w1]-w5+1;
			w5=w6=1;
			w1+=1;
			w2-=1;
		}
	}
	cout<<(sum/2);
	return 0;
}
