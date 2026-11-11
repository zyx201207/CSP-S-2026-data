#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
#include<stack>
using namespace std;
 long long n,m,a[100010],maxx=0;
int main()
 {
	  freopen("and.in","r",stdin);
	  freopen("and.out","w",stdout);
              
      cin>>n>>m;
      stack<long long>s1;
      stack<long long>s2;
    stack<long long>s3;
      for(int i=1;i<=n;i++){
       cin>>a[i];
       i++;}
       if(m==1){
       for(long long i=1;i<=n;i++){
		    if(a[i]>maxx)
		      maxx=a[i];}cout<<maxx;return 0;}
		      
		 long long t1,t2,t3,t4;
		for(long long i=1;i<n;i++)
		  for(long long j=i+1;j<=n;j++)
		  {
			t1=a[i]%2;t2=a[i]/2;t3=a[j]%2;t4=a[j]/2;
			s1.push(t1);s2.push(t2);
			while(t1!=0&&t2!=0)
            {
				t1=t2%2;t3=t4%2;
				t2=t2/2;t4=t4/2;
				s1.push(t1);s2.push(t2);
            }
            while(s1.empty()!=1||s2.empty()!=1){
			  if(s1.top()==s2.top())
			     s3.push(s1.top());
			     s1.pop();s2.pop();
			}
         }
     
      long long wf,xs=s3.top();
      wf=xs;
      s3.pop();int ss=1;
       while(s3.empty()!=1){
		   xs=s3.top();
      for(int i=1;i<=ss;i++)
        xs=xs*2;
      wf+=xs;
      if(wf>maxx)
        maxx=wf;
        s3.pop();
        ss++;
  }
     cout<<maxx;
      return 0;
 }
 
