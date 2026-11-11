#include<iostream>
using namespace std;
int n,a[200005],sum,step;
char word[200005],huiwen[900000001];
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
    cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i]>>word[i];
		sum += a[i];
	}
	int weishu = sum /2;

	for(int i = 1;i <= n;i++){
		
		for(int j = 1;j <= a[i];j ++){
			huiwen[j] = word[i];
		} 
	}
	for(int i = 1;i <= weishu;++i){
		for(int j = sum;j >= sum - weishu ;--j){
			if(huiwen[i] != huiwen[j]){
				step++;
				huiwen[i] = huiwen[j];
			}
		}
	}
	cout<<step;
	return 0;
}
