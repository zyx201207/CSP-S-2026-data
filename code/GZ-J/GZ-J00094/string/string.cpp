// GZ-J00094 清镇市第一中学 蒋煜
#include<bits/stdc++.h>
using namespace std;
string aas;
int n,num=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i<=n;i++){
		int a;
		char c;
		cin >> a >> c;
		for(int j=0;j<a;j++){
			aas[j]=c;
		}
	}
	int l=0,r=aas.size();
	for(int i=1;i<=r/2;i++){
		if(aas[l]!=aas[r]){
			num++;
			l++;
			r--;
		}else{
			l++;
			r--;
		}
	}
	cout << num;
	return 0;
}
