#include<bits/stdc++.h>
using namespace std;
#define rd read()
const int BUF=1<<20;
char buf[BUF],*head=buf,*tail=buf;
inline char gc(){
	if(head==tail)head=buf,tail=buf+fread(buf,1,BUF,stdin);
	return head==tail?0:*head++;
}
inline long long read() {
	int n=0,f=1;
	char c=gc();
	while('0'>c||c>'9'){
		if(c=='-')f=-1;c=gc();
	}
	while('0'<=c&&c<='9')n=n*10+c-'0',c=gc();
	return n*f;
}
long long a1[200005],a2[200005];
char dat1[200005],dat2[200005];
long long pre1[200005],pre2[200005];
int n;
inline long long get(long long x,long long *pre){
	for(int i=0;i<n;i++)if(pre[i]>x)return i;
}
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	n=rd;
	for(int i=0;i<n;i++)a1[i]=a2[n-i-1]=rd,dat1[i]=gc();
	pre1[0]=a1[0];pre2[0]=a2[0];
	a1[n]=1;
    for(int i=1;i<=n;i++)pre1[i]=a1[i]+pre1[i-1];
	for(int i=1;i<=n;i++)pre2[i]=a2[i]+pre2[i-1];
    long long res=0;
    long long it1=0,it2=0;
    long long i1=0,i2=0;
    while(i1<n&&i2<n&&it1<pre1[n-1]&&it2<pre2[n-1]){
    	//cout<<it1<<endl<<it2<<endl;
    	long long size1=pre1[i1+1]-it1-1;
    	long long size2=pre2[i2+1]-it2-1;
    	//printf("size1:%lld,size2:%lld,res:%lld \n",size1,size2,res);
    	if(size1<=size2){
    		if(dat1[get(it1,pre1)]!=dat2[get(it2,pre2)])res+=size1; 
    		it1+=size1;
    		it2+=size1;
    		i1++;
		}else {
			if(dat1[get(it1,pre1)]!=dat2[get(it2,pre2)])res+=size2; 
    		it1+=size2;
    		it2+=size2;
    		i2++;
		}//printf("size1:%lld,size2:%lld,res:%lld \n",size1,size2,res);
	}
	cout<<res/2;/*
	long long res=0;
	for(int i=0;i<n;i++){
		
	}
    */
	return 0;
}
