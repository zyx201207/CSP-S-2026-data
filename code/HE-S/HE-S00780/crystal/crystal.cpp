#include<bits/stdc++.h>
#define y first
#define x second
using namespace std;
const int N=5555555;

int n,m,cnt;
int a[N];
pair<int,int>b[N];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n-1);
	int mid=a[(n+1)/2-1];
	for(int i=0;i<n;i++){
		b[i].x=a[i];
		b[i].y=abs(mid-a[i]);
	}
	sort(b,b+n-1);
	
	for(int i=0;i<n;i++){
		if(m>=b[i].y){
			cnt++;
			m-=b[i].y;
			mid=max(mid,b[i].x);
		}
	}
	cout<<cnt;
	return 0;
}
