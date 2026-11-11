//Oct31==Dec25?
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    vector<long long> a,b;
    cin>>n>>m;// n=5,m=5
    for(long long i=0;i<n;i++){
        long long x;
        cin>>x;
        a.push_back(x); // 1 2 4 8 9
    }

for(long long i=1;i<=m;i++){
    for(long long j=0;j<a.size()-1;j++){
        if(a[j]>a[j+1]){
            long long jiaohuan;
            jiaohuan=a[j];
            a[j]=a[j+1];
            a[j+1]=jiaohuan;
        }
    }//1 2 4 8 9

        a[0]++;

} /*
第一次 2 2 4 8 9
第二次 3 2 4 8 9
第三次 3 3 4 8 9
第四次 4 3 4 8 9
第五次 4 4 4 8 9
*/
    for(long long i=0;i<a.size();i++){
        if(a[i]!=a[i+1]){
            cout<<i+1;
            break;
        }
    }
    fclose(stdin);
    fclose(stdout);
	return 0;
}
