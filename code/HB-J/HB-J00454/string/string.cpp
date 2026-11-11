#include<iostream>
#include<string>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int g=1,n=0,a=0;
	int l[1000];
	char m;
	string x;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a >> m;
		for(int j=0;j<a;j++){
			x+=m;
		}
	}
	int len = x.size();
	for(int j=0;j<len;j++){
		l[j]=0;
	}
	for(int j=0;j<len;j++){
		if(x[j] != x[j+1]){
			l[0] = j;
			continue;
		}
	}
	if(l[0]==0){
		cout << '0';
		return 0;
	}else{
		int q=l[0];
		for(int j=q+1;q<len;q++){
			if(x[j]!=x[0]){
				g++;
			}
		}cout << g;
	}
	return 0;
}
