#include<bits/stdc++.h>
using namespace std;
struct win{
	long long x;
	char y;
}; win a[10000010];
long long n;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdin);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].y;
	bool t=1;
	char z=a[1].y;
	for(int i=1;i<=n;i++){
	if(a[i].y==z)continue;
	else t=0;
	}
	if(t==1){
		cout<<0;
		return 0;
	}
    long long u=0;
    for(int i=1;i<=n;i++)u+=a[i].x;
    cout<<u/2;
	return 0;
}
