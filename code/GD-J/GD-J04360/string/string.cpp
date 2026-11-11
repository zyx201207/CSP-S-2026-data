#include <bits/stdc++.h>
using namespace std;
pair<long long, char> s[390718];
long long ans;long long LEN;
inline long long& l(int n){
	return s[n].first;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	
	int sing=0,c=0;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%lld %c",&s[i].first,&s[i].second);
		//printf("%d\n",i);
		LEN+=s[i].first;
		if(s[i].second==s[i-1].second){
			l(i-1)+=l(i);
			i--,n--,c++;
		}
	}
	sing=int(LEN%2!=0);
	/*int more=0,less=1;
	int i=1;
	while(LEN>sing||less!=more){
		if(s[more].first<=0){
			if(s[i].first>s[less].first)more=i;
			else more=less/*"more is less"/, less=i;
			i++;
		}
		
		if(s[more].first<s[less].first){
			int t=more;
			more=less;
			less=t;
		}
		if(less==more)
		s[more].first-=s[less].first;
		ans+=s[more].second==s[less].second?0:s[less].first;
		LEN-=less;
	}*/
	int curf=0, curb=n-1;
	long long t;
	//printf("%lld %c %lld %c\n",l(curf),s[curf].second,l(curb),s[curb].second);
	//for(long long i=0;i*2+sing<=LEN;i++){
	while(n>0){
		if(curf==curb)break;
		t=l(curf)<l(curb)?l(curf):l(curb);
		if(s[curf].second!=s[curb].second){
			ans+=t;
		}
		l(curf)-=t;l(curb)-=t;//i+=t;
		if(l(curf)<=0)curf++,n--;
		if(l(curb)<=0)curb--,n--;
		//printf("%lld %c %lld %c\n",l(curf),s[curf].second,l(curb),s[curb].second);
		
	}
	cout<<ans/*<<" "<<c*/;
	return 0;
}
