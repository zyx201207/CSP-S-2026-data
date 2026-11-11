#include<iostream>
using namespace std;
int n;
int a[200005];
char c[200005];
long long sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
//	freopen("string6.in","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	int pos1=1,pos2=n;
	long long sum1=a[1],sum2=0;
	long long now2=0;
	long long ans=0;
	while(pos1!=pos2){
		while((long long)(sum2+a[pos2]-now2)<=(long long)sum1){
			if(c[pos1]!=c[pos2]){
				ans+=a[pos2]-now2;
			}
			sum2+=a[pos2]-now2;
			now2=0;
			pos2--;
		}
		now2+=sum1-sum2;
		if(c[pos1]!=c[pos2]){
			ans+=sum1-sum2;
		}
		sum2=sum1;
//		cout<<ans<<" "<<pos1<<" "<<sum1<<" "<<pos2<<" "<<sum2<<" "<<now2<<endl;
		if((long long)(sum1+sum2)>=sum) break;
		
		pos1++;
		sum1+=a[pos1];
	}
//	cout<<sum<<endl;
	cout<<ans;
	return 0;
}
/*
sdfffaass
5
1 s
1 d
3 f
2 a
2 s
3

6
1 a
1 c
3 d
5 b
1 d
4 b
4
*/
