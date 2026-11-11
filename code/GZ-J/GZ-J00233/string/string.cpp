//GZ-J00233 赵传毅 贵阳市第三中学 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);
	string S="";
	string c;
	int N;
	int a;
	int sum=0;
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> a >> c;
		for(int j=0;j<a;j++){
			S+=c;
		}
	}
	for(int i=0;i<S.size();i++){
		if(S[i]!=S[S.size()-i]){
			S[i]=S[S.size()-i];
			sum+=1;
		}
	}
	cout << sum;
	return 0;
}
