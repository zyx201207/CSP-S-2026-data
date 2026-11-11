#include<iostream>
#include<cstdio>
using namespace std;
int n;
int a[500005];
char b[500005];
long long len,suml[500005],sumr[500005];
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        len+=a[i];
    }
    for(int i=1;i<=n;i++){
        suml[i]=a[i]+suml[i-1];
    }
    /*for(int i=1;i<=n;i++){
        cout<<suml[i]<<" ";
    }cout<<endl;*/
    for(int i=n;i>=1;i--){
        sumr[i]=a[i]+sumr[i+1];
    }
    /*(int i=1;i<=n;i++){
        cout<<sumr[i]<<" ";
    }cout<<endl;*/
    //前缀和、后缀和
    int l=0,r=n;//l\r均指向最后一个已加入的部分
    ans=0;

    while(l<r){
        while(suml[l]<=sumr[r] && l<r){//若左边数比右边少，l右移
            l++;
            if(suml[l]>sumr[r]){//特殊处理
                //cout<<"! l右移 l:"<<l<<" "<<r<<" "<<suml[l]<<" "<<sumr[r]<<endl;
                if(b[l]!=b[r]){
                    int k=sumr[r]-suml[l-1];
                    ans+=k;
                    //cout<<"    ans+ "<<ans;
                }
                //cout<<endl;
                break;
            }
            //cout<<"l右移 l:"<<l<<" "<<r<<" "<<suml[l]<<" "<<sumr[r]<<endl;
            if(b[l]!=b[r]){
                ans+=a[l];
                //cout<<"    ans+ "<<ans;
            }
            //cout<<endl;
        }

        while(sumr[r]<=suml[l] && l<r){//若右边数比左边少，r左移
            r--;
            if(sumr[r]>suml[l]){//特殊处理
                //cout<<"! r:"<<l<<" "<<r<<" "<<suml[l]<<" "<<sumr[r]<<endl;
                if(b[r]!=b[l]){
                    int k=suml[l]-sumr[r+1];
                    ans+=k;
                    //cout<<"    ans+ "<<ans;
                }
                //cout<<endl;
                break;
            }
            //cout<<"r左移 r:"<<l<<" "<<r<<" "<<suml[l]<<" "<<sumr[r]<<endl;
            if(b[r]!=b[l]){
                ans+=a[r];
                //cout<<"    ans+ "<<ans;
            }
            //cout<<endl;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
