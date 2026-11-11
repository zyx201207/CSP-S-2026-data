#include<iostream>
#include<string>
using namespace std;


int a[2000100];
int n,m,sum = 0,ans = 0;

void andand(int ii,int canshu){
	for(int i = ii; i < n - ii; i++){
		canshu &= a[i];
		if(ii == m){
			if(canshu > ans){
				ans = canshu;
			}	
		}
		else{
			andand(i+1,canshu);
		}
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	andand(1,a[0]);
	cout << ans;
	return 0;
}
