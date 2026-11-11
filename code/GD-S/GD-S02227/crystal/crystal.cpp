#include<bits/stdc++.h>
using namespace std;

const int MAXN=5*100000+20;
int n;
long long m;
long long a[MAXN];
int cnt=0;
int mid;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int maxxx=a[1];
	for (int i=2;i<=n;i++){
		if(a[i]>maxxx){
			maxxx=a[i];
		}
	}
	long long summ=0;
	for(int i=1;i<=n;i++){
		summ+=abs(maxxx-a[i]);
	}
	if(m>=summ){
		cout<<n;
		return 0;
	}
	if(n%2!=0){
		mid=n/2+1;
		int cha=a[2]-a[1];
		while(m>=0){
			int i=1;
			cnt+=2;
			m-=i*cha;
			if(m<0){
				cnt--;
				break;
			}
			i++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
