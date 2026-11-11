#include<bits/stdc++.h>
using namespace std;
char s[399999999],s1[399999999];
const int maxn=200005;
int n,cnt_slength,num_change,a[maxn];
char c[maxn];
int main(){
	freopen("string.in","r",stdin);         //qian wan bie wang le!
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		cnt_slength+=a[i];
	}int temp=1;
	for(int i=1;i<=n;i++){//paragraphs
		for(int j=1;j<=a[i];j++){//one paragraph
			s[temp]=c[i];
			temp++;
		}
	}
	//for(int i=1;i<=cnt_slength;i++)cout<<s[i]<<' '; //tiao shi zi fu shu zu yong
	int j1=1;
	for(int i=cnt_slength;i>=1;i--){
		s1[j1]=s[i];
		j1++;
	}
	//for(int i=1;i<=cnt_slength;i++)cout<<s1[i]; //tiao shi fan zhuan zi fu shu zu
	double temp666=1.0*cnt_slength/2;
	int half_cnt_slength=ceil(temp666);
	for(int i=1;i<=half_cnt_slength;i++){
		if(s[i]!=s1[i])num_change++;
	}
	cout<<num_change;
	return 0;
}

