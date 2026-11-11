#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10; 
struct seg{
	int times;
	char data;
}a[N];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].times>>a[i].data;
	}
	int i=1,j=n;
	long long cnt=0;
	while(i<j){
		if(a[i].times==0){
			i++;
		}
		else if(a[j].times==0){
			j--;
		}else if(a[i].data == a[j].data){
			int mn=min(a[i].times,a[j].times);
			a[i].times -= mn;
			a[j].times -= mn;
		}else if(a[i].data != a[j].data){
			int mn=min(a[i].times,a[j].times);
			a[i].times -= mn;
			a[j].times -= mn;
			cnt+=mn;
		}
	}
	cout<<cnt;
	return 0;
}
