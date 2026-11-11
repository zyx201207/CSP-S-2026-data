#include <bits/stdc++.h>
using namespace std;
const int M=2e5+10;
int L,qi[M],sum;
char r[M],qc[M];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin >> n;
	for(int i=0;i<2*n;i++){
		if(i%2==0){
			cin >> qi[i/2];
		}else{
			cin >> qc[i/2];
		}
	}
	//×÷ÓÃÊÇq to r 
	for(int m=0;m<qi.size();m++){
		a1+=qi[m];
		int a2=a1-qi[m];
		for(int i=a2;i<a1;i++){
			r[i] = qc[m]; 
			cout << r[i];
		}
	}	
	if(n==1) {
		cout << 0;
		return 0;
	}else if(n==2){
		if(qc[0]==qc[1]){
			cout << 0;
			return 0;
		}
		else{
			cout << min(qi[0],qi[1]);
			return 0;
		}
	}else{
		for(int a8=0;a8<=n;a8++){
			if(r[a8] != r[r.size()-a8+1]) sum++;
		}
	}cout << sum;
	return 0;
}
