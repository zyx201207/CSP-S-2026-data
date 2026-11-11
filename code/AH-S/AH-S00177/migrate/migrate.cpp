#include<bits/stdc++.h>
using namespace std;
bool pd1(vector<long long > dis,int i2,int j2,long long d2){
   queue<int> m;
   m.push(i2);
   int ti=i2-j2-1;
   int sum1=0;
   int mark=0;
   int cengshu=0;
       for(int i=2;i<ti;i++){
       while(!m.empty()){
       cengshu++;
       if(cengshu>mark) return false;
       for(int j=0;j<j2-m.front();j++){
         if(dis[m.front()+j]-dis[m.front()]>d2){
         j=100000000;
         continue;
       }
       if(m.front()==j2){
        sum1++;
		mark=cengshu;
        }
       if(sum1>=2) return true;
       m.push(m.front()+j);
       m.pop();
   }
   }
   }

return false;

}
void answer(vector<long long > mp,long long d1,int n1){
   long long sum=0;
   for(int i=0;i<n1;i++){
   for(int j=i+3;j<n1;j++){
   if(mp[j]-mp[i]<=d1){
       continue;
   }
   if(pd1(mp,i,j,d1)==true){
     sum++;
   }
}
}
cout<<sum<<endl;
}


int main(){
freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
 int c,t;
 cin>>c>>t;
 for(int i=0;i<t;i++){
  long long n;
  long long d;
  cin>>n>>d;
  vector<long long> ma;
  for(int j=0;j<n;j++)
  {
     long long x1;
     cin>>x1;
     ma.push_back(x1);
  }
  answer(ma,d,n);
  }
return 0;
}
