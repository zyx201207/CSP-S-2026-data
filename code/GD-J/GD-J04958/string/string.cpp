#include<iostream>
using namespace std;
const int N=2e5+10;
int n;
int a1[N],a2[N];
char c1[N],c2[N];
long long ans;
long long t;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    int cnt=0;
    for(int i=0;i<n;i++){
    	cin>>a1[i]>>c1[i];
    	t+=a1[i];
    	a2[n-i-1]=a1[i];
    	c2[n-i-1]=c1[i];
	}
	t/=2;
	int tr1=0,tr2=0,f1=0,f2=0;
	long long p1=0,p2=0;
	for(int i=0;i<n;i++){
		p1+=a1[tr1];
		if(p1>=t&&f1==0){
			a1[tr1]=a1[tr1]-(p1-t);
			f1=1;
		}
		p2+=a2[tr2];
		if(p2>=t&&f2==0){
			a2[tr2]=a2[tr2]-(p2-t);
			f2=1;
		}
		if(f1==0) tr1++;
		if(f2==0) tr2++;
	}
	int cnt1=0,cnt2=0;
	while(cnt1<=tr1&&cnt2<=tr2){
		if(c1[cnt1]==c2[cnt2]){
			if(a1[cnt1]<a2[cnt2]){
				a2[cnt2]-=a1[cnt1];
				cnt1++;
			}
			else if(a1[cnt1]>a2[cnt2]){
				a1[cnt1]-=a2[cnt2];
				cnt2++;
			}
			else if(a1[cnt1]==a2[cnt2]){
				cnt1++;
				cnt2++;
			}
			continue;
		}
		if(a1[cnt1]<a2[cnt2]){
			ans+=a1[cnt1];
			a2[cnt2]-=a1[cnt1];
			cnt1++;
		}
		else if(a1[cnt1]>a2[cnt2]){
			ans+=a2[cnt2];
			a1[cnt1]-=a2[cnt2];
			cnt2++;
		}
		else if(a1[cnt1]==a2[cnt2]){
			ans+=a1[cnt1];
			cnt1++;
			cnt2++;
		}
	}
	cout<<ans;
	return 0;
} 
