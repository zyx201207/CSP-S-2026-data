#include<iostream>
using namespace std;
unsigned long long a[200005][2];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	int x=0;
	a[0][1]=-1;
	for(int i=1;i<=n;i++){
		unsigned long long ai;
		char ci;
		cin>>ai>>ci;
		if(ci-'a'==a[x][1]) a[x][0]+=ai;
		else x++,a[x][0]=ai,a[x][1]=ci-'a';
	}//a
	if(x==1){cout<<0;return 0;}
	unsigned long long cnt=0;
	int l=1,r=x;
	while(r>l){
		if(a[l][1]==a[r][1]){
			if(a[l][0]==a[r][0]) l++,r--;
			else if(a[l][0]>a[r][0]) a[l][0]-=a[r][0],r--;
			else if(a[l][0]<a[r][0]) a[r][0]-=a[l][0],l++;
		}
		else{
			if(a[l][0]==a[r][0]) cnt+=a[l][0],l++,r--;
			else if(a[l][0]>a[r][0]) cnt+=a[r][0],a[l][0]-=a[r][0],r--;
			else if(a[l][0]<a[r][0]) cnt+=a[l][0],a[r][0]-=a[l][0],l++;
		}
	}
	cout<<cnt;
	return 0;
}
