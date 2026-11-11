#include <bits/stdc++.h>
using namespace std;
long long n,sum;
struct cl{
	long long a;
	char c;
};
cl stx[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> stx[i].a >> stx[i].c;
		sum+=stx[i].a;
	}
	sum/=2;
	long long l=1,r=n;
	while(l<r){
		//cout << stx[l].a << " " << stx[l].c << endl;
		//cout << stx[r].a << " " << stx[r].c << endl;
		if(stx[l].c==stx[r].c){
			if(stx[l].a>stx[r].a){
				sum-=stx[r].a;
				stx[l].a-=stx[r].a;
				stx[r].a=0;
				r--;
			}else if(stx[l].a<stx[r].a){
				sum-=stx[l].a;
				stx[r].a-=stx[l].a;
				stx[l].a=0;
				l++;
				
			}else{
				sum-=stx[l].a;
				stx[r].a=0;
				stx[l].a=0;
				r--;
				l++;
			}
		}else{
			if(stx[l].a>stx[r].a){
				stx[l].a-=stx[r].a;
				stx[r].a=0;
				r--;
			}else if(stx[l].a<stx[r].a){
				stx[r].a-=stx[l].a;
				stx[l].a=0;
				l++;
			}else{
				stx[r].a=0;
				stx[l].a=0;
				r--;
				l++;
			}
		}
	}
	//cout << stx[l].a << " " << stx[r].a << endl;
	sum=sum-max(stx[l].a/2,stx[r].a/2);
	cout << sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
