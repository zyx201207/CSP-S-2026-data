#include<bits/stdc++.h>
#include<vector>
using namespace std;
long n,a;
string c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	vector<string> x;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			x.push_back(c);
		}
	}
	int l=x.size();
	int sum=0;
	int i=0;
	while(i<=l/2){
		if(x[i]!=x[l-1-i]){
			sum++;
		}
		i++;
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
