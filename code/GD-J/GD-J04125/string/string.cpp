#include<iostream>
using namespace std;
int n,num[100005];
string a[10005];
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> num[i];
		cin >> a[i];
	}
	for(int i = 1;i<=n/2;i++){
		ans+=num[i];
	} 
	cout<< ans;
}
