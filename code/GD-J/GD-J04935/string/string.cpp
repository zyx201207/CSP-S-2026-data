#include <bits/stdc++.h>
using namespace std;
const int MA=2*114514;
int n;
long long ans;
int a[MA];
char c[MA];
void genxin(char &cc,int &x,int xb){
	cc=c[xb];
	x=a[xb];
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)cin >> a[i] >> c[i];
	int i=1,j=n;
	int a1=a[i],a2=a[j];
	char c1=c[i],c2=c[j];
	while(i<j){
		if(c1==c2){
			if(a1>a2){
				j--;
				a1-=a2;
				genxin(c2,a2,j);
			}else if(a1==a2){
				i++,j--;
				genxin(c1,a1,i);
				genxin(c2,a2,j);
			}else{
				i++;
				a2-=a1;
				genxin(c1,a1,i);
			}
		}else{
			if(a1>a2){
				ans+=a2;
				j--;
				a1-=a2;
				genxin(c2,a2,j);
			}else if(a1==a2){
				ans+=a1;
				i++,j--;
				genxin(c1,a1,i);
				genxin(c2,a2,j);
			}else{
				ans+=a1;
				i++;
				a2-=a1;
				genxin(c1,a1,i);
			}
		}
	}
	cout << ans;
	return 0
}

