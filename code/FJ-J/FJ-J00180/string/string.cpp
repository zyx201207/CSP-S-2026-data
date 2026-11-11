#include <bits/stdc++.h>
using namespace std;
struct stu{
	int a;
	char c;
};

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	stu x[n+5];
	int m=0;
	int r=0;
	char k[100005];
	for(int i=0;i<n;i++){
		cin>>x[i].a>>x[i].c;
		for(int j=r;j<r+x[i].a;j++){
			k[j]=x[i].c;
			r++;
		}
	}
	for(int i=0;i<r/2;i++){
		if(k[i]!=k[r-1-i]){
			k[r-1-i]=k[i];
			m++;
		}
	}
	cout<<m;
	return 0;
} 
