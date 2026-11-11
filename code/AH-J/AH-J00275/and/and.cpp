//and
#include<iostream>
#include<cmath>
#include<algorithm>
#include<iomanip>
using namespace std;
int n,m,a[200005],mx=0;
bool cmp(int x,int y){
    return x>=y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>mx){
            mx=a[i];
        }
	}
	long long sum;
	sort(a+1,a+n+1,cmp);
	sum=a[1];
	for(int i=2;i<=m;i++){
        if(a[i+1] != 0){
            sum = (sum&a[i]);
        }
	}
	if(m==1){
        cout<<mx;
	}else{
        cout<<sum;
	}
	return 0;
}
