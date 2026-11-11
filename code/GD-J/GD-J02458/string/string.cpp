#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
long long l[200005],r[200005];
int ml,mr;
char s[200005];
char sl[200005],sr[200005];
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		sum+=a[i];
	}
	int d;
	long long num=sum/2;
//	cout<<num<<endl;
	for(int i=1;i<=n;i++){
		if(num>=a[i]){
			num-=a[i];
		}else{
			d=i;
			break;
		}
	}
//	cout<<num<<" "<<d<<endl<<endl;
	for(int i=1;i<=d;i++){
		if(i==d){
			if(num){
				sl[++ml]=s[i];
				l[ml]=sum;
			}
			break;
		}
		sl[++ml]=s[i];
		l[ml]=a[i];
	}
/*	for(int i=1;i<=ml;i++){
		cout<<l[i]<<" "<<sl[i]<<endl;
	}
	cout<<endl;*/
	for(int i=d;i<=n;i++){
		if(i==d){
			if(sum%2){
				sr[++mr]=s[i];
				r[mr]=a[i]-num-1;
				if(!r[mr]){
					mr--;
				}
				continue;
			}
			sr[++mr]=s[i];
			r[mr]=a[i]-num;
			continue;
		}
		sr[++mr]=s[i];
		r[mr]=a[i];
	}
/*	for(int i=1;i<=mr;i++){
		cout<<r[i]<<" "<<sr[i]<<endl;
	}
	cout<<endl;*/
	int p1=ml,p2=1;
	while(p1>=1&&p2<=mr){
//		cout<<sl[p1]<<" "<<sr[p2]<<" "<<l[p1]<<" "<<r[p2]<<" "<<ans<<endl;
		if(l[p1]>r[p2]){
			if(sl[p1]!=sr[p2]){
				ans+=min(l[p1],r[p2]);
			}
			l[p1]-=r[p2];
			p2++;
		}else{
			if(sl[p1]!=sr[p2]){
				ans+=min(l[p1],r[p2]);
			}
			r[p2]-=l[p1];
			p1--;
		}
//		cout<<sl[p1]<<" "<<sr[p2]<<" "<<l[p1]<<" "<<r[p2]<<" "<<ans<<endl;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}/*
3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

*/
