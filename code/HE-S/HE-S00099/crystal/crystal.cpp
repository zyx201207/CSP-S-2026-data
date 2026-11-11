#include<iostream>
#include<algorithm>
using namespace std;
int n,a[500001],cha;
long long int m,cnt,mx=0,m2;
bool mark;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	m2=m;
	for(int j=n-1;j>=0;j--){
	 	m=m2;
		cnt=1;
    	mark=true;
		for(int i=j-1;i>=0;i--){
			cha=a[j]-a[i];
			if(m>=cha){
				m=m-cha;
				cnt++;
			}else{
				mark=false;
				break;
			}
		}
		if(cnt>mx){
			mx=cnt;
		}
		if(mark){
			cout << mx;
			return 0;
		}
	}
	cout << mx;
	return 0;
} 
