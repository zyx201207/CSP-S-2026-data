#include<bits/stdc++.h>
using namespace std;
struct hu{
	long long ai;
	string si;
}a[200006];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("srting.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].ai>>a[i].si;
	}
	long long min1=0;
	long long zuo=1,you=n;
	while(zuo<you){
		long long cha=min(a[zuo].ai,a[you].ai); 
		if(a[zuo].si!=a[you].si){
			min1+=cha;
			if(a[zuo].ai>a[you].ai){
				a[zuo].ai-=cha;
				you--;
			}else if(a[zuo].ai<a[you].ai){
				a[you].ai-=cha;
				zuo++;
			}else{
				zuo++;
				you--;
			}
		}else{
			if(a[zuo].ai>a[you].ai){
				a[zuo].ai-=cha;
				you--;
			}else if(a[zuo].ai<a[you].ai){
				a[you].ai-=cha;
				zuo++;
			}else{
				zuo++;
				you--;
			}
		}
	}
	cout<<min1;
	return 0;
}
