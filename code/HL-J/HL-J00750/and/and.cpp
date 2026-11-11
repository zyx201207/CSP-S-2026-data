#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a,b;
	int num[2005];
	cin >> a >>b;
	for(int i=0;i<a;i++) cin >> num[i];
	int ans=num[0];
	if(a==b){
		for(int i=0;i<a-1;i++){
			ans=ans & num[i+1];
		}
		cout << ans;
	}else if(b==1){
		sort(num,num+a);
		cout << num[a-1];
	}
	return 0;
}