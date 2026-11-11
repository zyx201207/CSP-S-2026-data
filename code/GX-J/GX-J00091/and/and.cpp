#include<iostream>
int arr[100005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    std::cin>>n>>m;
    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }
    int max_n=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<i+m;j++){
            if(arr[j]==arr[j+1]){
                continue;
            }
            max_n=std::max(arr[j]&arr[j+1],max_n);
        }
    }
    std::cout<<max_n;

    return 0;
}
