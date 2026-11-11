#include<bits/stdc++.h>
using namespace std;
struct st{
	long long l;
	char c;
}; 
st a[200005];
st b[200005];
st c[250005];
int blen,cl;
long long s[200005];
long long sum,cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].l>>a[i].c;
		if(a[i].c!=a[i-1].c){
			blen++;
			b[blen].c=a[i].c;
			b[blen].l=a[i].l;
		}else{
			b[blen].l+=a[i].l;
		}
	}
	
	for(int i=1;i<=blen;i++){
		s[i]=s[i-1]+b[i].l;
	}
	sum=s[blen];
	int mid,mid2=-1,mid3=-1;
	for(int i=1;i<=blen;i++){
		if(s[i]>sum/2){
			mid=i;
			break;
		}
	}
	for(int i=1;i<=blen;i++){
		if(i<mid){
			cl++;
			c[i].l=b[i].l;
			c[i].c=b[i].c;
		}
		if(i==mid){
			if(sum/2-s[i-1]!=0){
				cl++;
				c[cl].l=sum/2-s[i-1];
				c[cl].c=b[i].c;
				if(sum%2==1){
					cl++;
					mid2=cl;
					c[cl].l=1;
					c[cl].c=b[i].c;
					cl++;
					mid3=cl;
					c[cl].l=b[i].l-c[cl-2].l-1;
					c[cl].c=b[i].c;
				}else{
					cl++;
					mid3=cl;
					c[cl].l=b[i].l-c[cl-1].l;
					c[cl].c=b[i].c;
				}
			}else{
				if(sum%2==1){
					cl++;
					mid2=cl;
					c[cl].l=1;
					c[cl].c=b[i].c;
					cl++;
					mid3=cl;
					c[cl].l=b[i].l-1;
					c[cl].c=b[i].c;
				}else{
					cl++;
					mid3=cl;
					c[cl].l=b[i].l;
					c[cl].c=b[i].c;	
				}
			}
		}
		if(i>mid){
			cl++;
			c[cl].l=b[i].l;
			c[cl].c=b[i].c;
		}
	}
/*	for(int i=1;i<=cl;i++){
		cout<<c[i].l<<' '<<c[i].c<<endl;
	}*/
	long long now=0,now2=0,j=-1;
	if(mid2!=-1){
		for(int i=mid2-1;i>=1;i--){
			now+=c[i].l;
			if(j==-1){
				j=mid2+1;
				now2+=c[j].l;
				if(now>now2){
					if(c[j].c!=c[i].c){
						if(now>=now2){
							cnt+=c[j].l;
						}else{
							cnt=cnt+(now-(now2-c[j].l));
						}
					}
				}
				while(now>now2){
					j++;
					now2+=c[j].l;
					if(c[j].c!=c[i].c){
						if(now>=now2){
							cnt+=c[j].l;
						}else{
							cnt=cnt+(now-(now2-c[j].l));
						}
					}
				}
			}else{
				if(now-c[i].l<now2){//¾ÉÕË 
					if(c[j].c==c[i].c){
						
					}else{
						cnt=cnt+min((now2-(now-c[i].l)),(long long)c[i].l);
					}
				}
				while(now>now2){
					j++;
					now2+=c[j].l;
					if(c[j].c!=c[i].c){
						if(now>=now2){
							cnt+=c[j].l;
						}else{
							cnt=cnt+(now-(now2-c[j].l));
						}
					}
				}
			}
		}
	}else{
		for(int i=mid3-1;i>=1;i--){
			now+=c[i].l;
			if(j==-1){
				j=mid3;
				now2+=c[j].l;
				if(now>now2){
					if(c[j].c!=c[i].c){
						if(now>=now2){
							cnt+=c[j].l;
						}else{
							cnt=cnt+(now-(now2-c[j].l));
						}
					}
				}
				while(now>now2){
					j++;
					now2+=c[j].l;
					if(c[j].c!=c[i].c){
						if(now>=now2){
							cnt+=c[j].l;
						}else{
							cnt=cnt+(now-(now2-c[j].l));
						}
					}
				}
			}else{
				if(now-c[i].l<now2){//¾ÉÕË 
					if(c[j].c==c[i].c){
						
					}else{
						cnt=cnt+min((now2-(now-c[i].l)),(long long)c[i].l);
					}
				}
				while(now>now2){
					j++;
					now2+=c[j].l;
					if(c[j].c!=c[i].c){
						if(now>=now2){
							cnt+=c[j].l;
						}else{
							cnt=cnt+(now-(now2-c[j].l));
						}
					}
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}
/*
5
13 e
1 a
7 u
4 t
9 y

*/
