#include<iostream>
using namespace std;
int n,a[99999999],m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,a[99999999],m,big,small,time=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		big=max(a[i],a[i-1]);
		small=min(a[i],a[i-1]);
		a[i]=big;
		a[i-1]=small;
	}
	for(int i=1;i<=n;i++){
		if(a[i]<a[i+1]&&m>=a[i+1]-a[i]){
			a[i]=a[i+1];
			m=m-a[i+1]+a[i];
		}
	}
	if(m>0){
		for(int i=1;i<=m;i++){
			if(a[1]<a[2]){
				a[1]++;
				m--;
			}
			if(a[1]==a[2]){
				if(m%2==0){
					a[1]++;
					a[2]++;
				}
				else{
					break;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==a[i-1]){
			time++;
		}
	}
	cout<<time;
	return 0;
} 
