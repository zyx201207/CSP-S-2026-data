#include<bits/stdc++.h>
using namespace std;
bool cmp(long long a1,long long a2){
  return a1<a2;
  }
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
  long long n,m;
  cin>>n>>m;
  vector<long long> a;
  for(int i=0;i<n;i++){
  long long number;
  cin>>number;
  a.push_back(number);
  }
  long long ans=1;
  if(n<=5&&m<=10){
  for(int i=-20;i<22;i++){
  vector<long long> cha;
  for(int j=0;j<n;j++){
  if((i-a[j])>=0){
  long long cha1=i-a[j];
  cha.push_back(cha1);
  }
  }
  if(!cha.empty()&&cha.size()>=2){
	  auto aa=cha.size();
  sort(cha.begin(),cha.end(),cmp);
  long long sum1=0;
  long long sum2=0;
  for(unsigned int k=0;k<aa;k++){
       if(sum1+cha[k]<=m){
       sum2++;
       sum1+=cha[k];
  }
  }
  ans=max(ans,sum2);
  }
  }
  cout<<ans;
  return 0;
  }
  return 0;
  }
  
