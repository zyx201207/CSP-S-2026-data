#include <bits/stdc++.h>
using namespace std;
int a[101010101];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
    }
    int ans = 0;
    if(k == 2){
        for(int i = 1;i <= n;i++){
            for(int j = i + 1;j <= n;j++){
                ans = max(ans,a[i] & a[j]);
            }
        }
    }else if(k == 3){
        for(int i = 1;i <= n;i++){
            for(int j = i + 1;j <= n;j++){
                for(int l = j + 1;l <= n;l++){
                    ans = max(ans,a[i] & a[j] & a[l]);
                }
            }
        }
    }else if(k == 4){
        for(int i = 1;i <= n;i++){
            for(int j = i + 1;j <= n;j++){
                for(int l = j + 1;l <= n;l++){
                    for(int s = l + 1;s <= n;s++){
                        ans = max(ans,a[i] & a[j] & a[l] & a[s]);
                    }
                }
            }
        }
    }else if(k == 5){
        for(int i = 1;i <= n;i++){
            for(int j = i + 1;j <= n;j++){
                for(int l = j + 1;l <= n;l++){
                    for(int s = l + 1;s <= n;s++){
                        for(int r = s + 1;r <= n;r++){
                            ans = max(ans,a[i] & a[j] & a[l] & a[s] & a[r]);
                        }
                    }
                }
            }
        }
    }else if(k == 6){
        for(int i = 1;i <= n;i++){
            for(int j = i + 1;j <= n;j++){
                for(int l = j + 1;l <= n;l++){
                    for(int s = l + 1;s <= n;s++){
                        for(int r = s + 1;r <= n;r++){
                            for(int g = r + 1;g <= n;g++){
                                ans = max(ans,a[i] & a[j] & a[l] & a[s] & a[r] & a[g]);
                            }
                        }
                    }
                }
            }
        }
    }else if(k == 7){
        for(int i = 1;i <= n;i++){
            for(int j = i + 1;j <= n;j++){
                for(int l = j + 1;l <= n;l++){
                    for(int s = l + 1;s <= n;s++){
                        for(int r = s + 1;r <= n;r++){
                            for(int g = r + 1;g <= n;g++){
                                for(int u = g + 1;u <= n;u++){
                                    ans = max(ans,a[i] & a[j] & a[l] & a[s] & a[r] & a[g] & a[u]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }else if(k == 7){
        for(int i = 1;i <= n;i++){
            for(int j = i + 1;j <= n;j++){
                for(int l = j + 1;l <= n;l++){
                    for(int s = l + 1;s <= n;s++){
                        for(int r = s + 1;r <= n;r++){
                            for(int g = r + 1;g <= n;g++){
                                for(int u = g + 1;u <= n;u++){
                                    for(int w = u + 1;w <= n;w++){
                                        ans = max(ans,a[i] & a[j] & a[l] & a[s] & a[r] & a[g] & a[u] & a[w]);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }else if(k == 8){
        for(int i = 1;i <= n;i++){
            for(int j = i + 1;j <= n;j++){
                for(int l = j + 1;l <= n;l++){
                    for(int s = l + 1;s <= n;s++){
                        for(int r = s + 1;r <= n;r++){
                            for(int g = r + 1;g <= n;g++){
                                for(int u = g + 1;u <= n;u++){
                                    for(int w = u + 1;w <= n;w++){
                                        for(int b = w + 1;b <= n;b++){
                                            ans = max(ans,a[i] & a[j] & a[l] & a[s] & a[r] & a[g] & a[u] & a[w] & a[b]);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
