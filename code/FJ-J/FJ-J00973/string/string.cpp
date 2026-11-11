#include<bits/stdc++.h>
using namespace std;
long long n,cnt,sum,p1,p2,s1,s2;
struct{
	long long w;
	char c;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].w>>a[i].c;
		cnt+=a[i].w;
	}if(cnt<100000 && n<=2000){
		char b[100005];
		long long aaa=0;
		for(int i=1;i<=n;i++){
			for(int j=aaa+1;j<=aaa+a[i].w;j++){
				b[j]=a[i].c;
			}aaa+=a[i].w;
		}for(int i=1;i<=cnt/2;i++){
			if(b[i]!=b[cnt-i+1]) sum++;
		}cout<<sum;
		return 0;
	}int l=1,r=n;
	p1=1;
	p2=cnt;
	s1=a[l].w;
	s2=cnt-a[r].w+1;
	while(l<r){
		if(a[r].c!=a[l].c){
			sum+=min(s1-p1+1,p2-s2+1);
		}if(s1>cnt-s2+1){
			p1=cnt-s2+2;
			p2=s2-1;
			r--;
			s2-=a[r].w;			
		}else if(s1==cnt-s2+1){
			p1=s1+1;
			p2=s2-1;
			l++;
			r++;
			s1+=a[l].w;
			s2-=a[r].w;
		}
		else{
			p1=s1+1;
			p2=cnt-s1;
			l++;
			s1+=a[l].w;
		}if(s1>cnt/2){
			while(s1<p2){
				if(a[r].c!=a[l].c){
					sum+=p2-s2+1;
					p2=s2-1;
					s2-=a[r-1].w;
				}r--;
			}
			break;
		}if(s2<cnt/2){
			while(s1<p2){
				if(a[r].c!=a[l].c){
					sum+=s1-p1+1;
					p1=s1+1;
					s1+=a[l+1].w;
				}l++;
			}break;
		}
	}cout<<sum;
	return 0;
}
