#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n = 0,m = 0;
	int sum = 0,Times = 0,maxans = 0,ans = 0;
	int cyl[5005] = {0};
	int sum1[5005] = {0};//³õÊ¼»¯
	cin >> n;
	cin >> m;
	for(int i = 1;i <= n;i++){
		cin >> cyl[i];
	}
	sort(cyl+1,cyl+1+n);
	for(int i = 2;i <= n;i++){
		sum1[i-1] = cyl[i]-cyl[i-1];
	}
	for(int i = n-1;i >= 1;i--){
		ans = 1;
		sum = 0;
		Times = i;
		while((sum <= m) && (Times >= 1)){
			sum = sum*2+sum1[Times-1];
			Times--;
			ans++;
			if(sum > m){
				ans--;
			}
		}
		if(i == n){
			maxans = ans;
		}
		maxans = max(maxans,ans);
	}
	cout<<maxans; 
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
