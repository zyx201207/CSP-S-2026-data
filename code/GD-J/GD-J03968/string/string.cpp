#include<bits/stdc++.h>
using namespace std;
int n;
long long l1,r1,sum,ans=0;
struct aaa{
	long long r,l;
	char w;
};
aaa s[100000],l2[100000],r2[100000];
int main(){
	freopen("string.in",'r',stdin);
	freopen("string.out",'w',stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i].l>>s[i].w;
		sum+=s[i].l;
		s[i].l=sum-s[i].l;
		s[i].r=sum-1;
	}
	long long min=sum/2;
	int a=sum%2;
	r1=n-1;
	while(l1<r1){
		if(s[l1].l<min and s[l1].r<min){
			l2[l1].r=s[l1].r;
			l2[l1].l=s[l1].l;
			l2[l1].w=s[l1].w;
			l1++;
		}
		else if(s[l1].l<min and s[l1].r>min){
			l2[l1].r=min;
			l2[l1].l=s[l1].l;
			l2[l1].w=s[l1].w;
			
			r2[l1].r=s[l1].r;
			r2[l1].l=min+a;
			r2[l1].w=s[l1].w;
			l1++;
		}
		if(s[r1].l>min){
			r2[r1].r=s[r1].r;
			r2[r1].l=s[r1].l;
			r2[r1].w=s[r1].w;
			r1--;
		}
	}
	int fl=0,fr=l1-1,ll=l1-1,lr=n-1;
	while(fl<=ll and fr<=lr){
		if(l2[fl].r-l2[fl].l>r2[lr].r-r2[lr].l){
			if(l2[fl].w!=r2[lr].w) ans+=r2[lr].r-r2[lr].l;
			l2[fl].l+=r2[lr].r-r2[lr].l;
			lr--;
		}
		else if(l2[fl].r-l2[fl].l==r2[lr].r-r2[lr].l){
			if(l2[fl].w!=r2[lr].w) ans+=r2[lr].r-r2[lr].l+1;
			fl++;
			lr--;
		}
		else{
			if(l2[fl].w!=r2[lr].w) ans+=l2[fl].r-l2[fl].l;
			r2[lr].l+=l2[fl].r-l2[fl].l;
			fl++;
		}
	}
	cout<<ans;
	
}
