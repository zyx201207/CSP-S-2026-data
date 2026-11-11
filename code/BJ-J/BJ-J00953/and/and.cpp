#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> num;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        num.push_back(temp);
    }
    int maxand=0;
    for(int i=0;i<n-1;i++){//m=2
        for(int j=i+1;j<n;j++){
            if(num[i]&num[j]>maxand) maxand = num[i]&num[j];
        }
    }
    cout<<maxand;
    return 0;
}
