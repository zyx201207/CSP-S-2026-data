#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin >> n;
	string a;
	for(int i = 0;i < n;i++){
		int b;
		char c;
		scanf("%d",&b);
		cin >> c;
		for(int j = 0;j < b;j++){
			a = a + c;
		}
	}
	long long cnt = 0;
	if(a.size() % 2 == 0){
		for(long long i = 0,j = a.size()-1,k = a.size()/2-1,l = a.size();i <= k;i++,j--,k--,l++){
			if(a[i] != a[j]){
				cnt++;
			}
	    	if(a[k] != a[l]){
	    		cnt++;
			}if(a[i] != a[j] && a[k] != a[l] && i == k){
				cnt--;
			}
		}
	}else{
		for(long long i = 0,j = a.size()-1,k = a.size()/2-1,l = a.size()+1;i <= k;i++,j--,k--,l++){
			if(a[i] != a[j]){
				cnt++;
			}
	    	if(a[k] != a[l]){
	    		cnt++;
			}if(a[i] != a[j] && a[k] != a[l] && i == k){
				cnt--;
			}
		}
	}
	cout << cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
