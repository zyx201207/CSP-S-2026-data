#include<bits/stdc++.h>
using namespace std;
struct s{
	long long x,num;
};
bool cmp(s c,s d){
	return c.num>d.num;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,a[20005],m,sum=0,ma=0,maxx=0,c[10005],l=0;
	s b[100005]={0};
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[a[i]].x++;
		b[a[i]].num=a[i];
		l=max(l,a[i]);
	}
	sum=b[l].num;
	l--;
	while(1){
		if(b[l].num==0){
			l--;
		}else if(l>0){
			if(m>1){
				if(b[l].x>0){
					b[l].x--;
					m--;
					sum=(sum&l);
				}else{
					l--;
				}
			}else{
				break;
			}
		}
	}
	cout<<sum;
	return 0;
}