#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

struct node{
	int sum;
	char c;
};

const int N=2e5+5;

string str;
node re[N];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin >> n; 
	for(int i=0;i<n;i++){
		cin >> re[i].sum >> re[i].c;
		for(int j=0;j<re[i].sum;j++){
			str+=re[i].c;
		}
	}
	int len=str.length();
	long long ans=0;
	for(int i=0;i<len>>1;i++){
		if(str[i]!=str[len-i-1])ans++;
	}
	cout << ans;
	return 0;
}
