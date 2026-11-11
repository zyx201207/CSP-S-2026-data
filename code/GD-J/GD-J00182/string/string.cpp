#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
struct stu{
	long long x;
	char c;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
	}
	long long sum=0;
	int i=1,j=n;
	while(i<j){
		int w=min(a[i].x,a[j].x);
		if(a[i].c==a[j].c){
			a[i].x-=w;
			a[j].x-=w;
		}else{
			a[i].x-=w;
			a[j].x-=w;
			sum+=w;
		}
		if(a[i].x==0){
			i++;
		}
		if(a[j].x==0){
			j--;
		}
	}
	cout<<sum;
	
	return 0;
} 
