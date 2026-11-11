#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,j;
long long cnt;
struct a{
	long long c2;
	char c;
}xw[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>xw[i].c2>>xw[i].c;
	}
	for(int i=1;i<n;i++){
		if(xw[i].c==xw[i+1].c){
			m++;
		}
	}
	if(m==n-1){
		cout<<0;
		return 0;
	}
	j=n;
	for(int i=1;i<=n;i++){
		if(xw[i].c!=xw[j].c){
			if(xw[i].c2>xw[j].c2){
				cnt+=xw[j].c2;
				xw[i+1].c2+=xw[i].c2-xw[j].c2;
			}
			if(xw[i].c2<xw[j].c2){
				cnt+=xw[j].c2;
				xw[j-1].c2+=xw[j].c2-xw[i].c2;
			}else{
				cnt+=xw[j].c2;
			}
		}else{
			if(xw[i].c2>xw[j].c2){
				xw[i+1].c2+=xw[i].c2-xw[j].c2;
			}
			if(xw[i].c2<xw[j].c2){
				xw[j-1].c2+=xw[j].c2-xw[i].c2;
			}else{
				cnt+=xw[j].c2;
			}
		}
		j--;
		if(i>=j){
			break;
		}
	}
	cout<<cnt;
	return 0;
}

